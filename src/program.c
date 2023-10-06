#define BASE_IO 0xE0000000
#define BASE_VIDEO 0x80000

#define LED (BASE_IO + 4)

#define MEM_WRITE(_addr_, _value_) (*((volatile unsigned int *)(_addr_)) = _value_)
#define MEM_READ(_addr_) *((volatile unsigned int *)(_addr_))

unsigned int val(unsigned int i)
{
    if (i < 1024/8)
        return 0xFFFFFFFF;
    return 0x55550000;
}

void main(void)
{
    for (unsigned int i = 0; i < 1024*768/8; i += 4) {
        MEM_WRITE(BASE_VIDEO + i, val(i));
    }

    int error_detected = 0;
    for (unsigned int i = 0; i < 1024*768/8; i += 4) {
        unsigned int v = MEM_READ(BASE_VIDEO + i);
        if (v != val(i)) {
            error_detected = 1;
        }
    }

    MEM_WRITE(LED, error_detected ? 0xFF : 0x01);

    for (;;);
}
