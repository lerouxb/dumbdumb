from machine import Timer, UART
import micropython

uart = UART(2, 115200)
uart.init(115200, bits=8, parity=None, stop=1)
uos.dupterm(uart)

timer = Timer(-1)

def schedule_poll(ignore=None):
    micropython.schedule(check, 0)

def check(ignore=None):
    if uart.any():
        uos.dupterm_notify(uart)
    timer.init(period=10, mode=Timer.ONE_SHOT, callback=schedule_poll)

check()

