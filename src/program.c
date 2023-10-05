#define BASE_IO 0xE0000000
#define LED (BASE_IO + 4)

#define MEM_WRITE(_addr_, _value_) (*((volatile unsigned int *)(_addr_)) = _value_)

void main(void)
{
    MEM_WRITE(LED, 0x5555);
    for (;;) {
    }
}
