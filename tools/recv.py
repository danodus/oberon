import sys
import serial
import time

REQ = 0x20
REC = 0x21
SND = 0x22
ACK = 0x10
NAK = 0x11

def main(argv):
    if (len(argv) < 2):
        print("Usage: recv.py <serial device> <filename>")
        exit(0)
    else:
        try:
            ser = serial.Serial(argv[0], baudrate=19200)
        except serial.serialutil.SerialException:
            print("Unable to open the serial device {0}".format(argv[0]))
            exit(1)

        ser.write(SND.to_bytes(1, "little"))
        ser.write(argv[1].encode())
        ser.write(b"\0")
        b = int.from_bytes(ser.read(1), "little")
        if b == NAK:
            print("NAK received")
            return
        elif b == ACK:
            print("ACK received")
        else:
            print("Unknown")
            return
        
        f = open(argv[1], "wb")
        while True:
            length = int.from_bytes(ser.read(1), "little")
            print("receiving %d bytes" % length)
            b = ser.read(length)
            f.write(b)
            ser.write(ACK.to_bytes(1, "little"))
            if length < 255:
                break
        print("Done.")
        f.close()
        ser.close()
    exit(0)


if __name__ == "__main__":
    main(sys.argv[1:])
