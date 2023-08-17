import sys
import serial
import time

REQ = 0x20
REC = 0x21
SND = 0x22
ACK = 0x10
NAK = 0x11

def wait_ack(ser):
    b = int.from_bytes(ser.read(1), "little")
    if b == NAK:
        print("NAK received")
        return False
    elif b == ACK:
        print("ACK received")
    else:
        print("Unknown")
        return False
    return True


def main(argv):
    if (len(argv) < 2):
        print("Usage: send.py <serial device> <filename>")
        exit(0)
    else:
        try:
            ser = serial.Serial(argv[0], baudrate=19200)
        except serial.serialutil.SerialException:
            print("Unable to open the serial device {0}".format(argv[0]))
            exit(1)

        try:
            f = open(argv[1], "rb")
        except:
            print("Unable to open {0}".format(argv[1]))
            exit(1)
        
        ser.write(REC.to_bytes(1, "little"))
        ser.write(argv[1].encode())
        ser.write(b"\0")

        if not wait_ack(ser):
            return
        
        while True:
            chunk = f.read(255)
            if not chunk:
                break
            length = len(chunk)
            print("sending %d bytes" % length)
            ser.write(length.to_bytes(1, "little"))
            ser.write(chunk)

            if not wait_ack(ser):
                break

            if length < 255:
                break

        if not wait_ack(ser):
            return

        print("Done.")
        f.close()
        ser.close()
    exit(0)


if __name__ == "__main__":
    main(sys.argv[1:])
