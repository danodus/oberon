#define BASE_IO 0xE0000000
#define BASE_VIDEO 0x1000000

#define LED (BASE_IO + 4)

#define MEM_WRITE(_addr_, _value_) (*((volatile unsigned int *)(_addr_)) = _value_)
#define MEM_READ(_addr_) *((volatile unsigned int *)(_addr_))

unsigned int val(int x, int y, unsigned int c)
{
    if (x == 0 || x == 19 || y == 0 || y == 479)
        return 0xFFFFFFFF;
    return c;
}

void main(void)
{
    unsigned int counter = 0;
    int error_detected = 0;
    for (;;) {
        for (int y = 0; y < 480; ++y) {
            for (int x = 0; x < 20; ++x) {
                unsigned int i = y * (640 / 8) + x * 4;
                MEM_WRITE(BASE_VIDEO + i, val(x, y, counter));
            }
        }

        for (int y = 0; y < 480; ++y) {
            for (int x = 0; x < 20; ++x) {
                unsigned int i = y * (640 / 8) + x * 4;
                unsigned int v = MEM_READ(BASE_VIDEO + i);
                if (v != val(x, y, counter))
                    error_detected = 1;
            }
        }

        MEM_WRITE(LED, error_detected ? 0xFF : 0x01);
        counter++;
    }
}
