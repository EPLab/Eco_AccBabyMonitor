import threading
from Queue import Queue
import time

class test(threading.Thread):

    def __init__(self):
        threading.Thread.__init__(self)
        self._stop = threading.Event()
        self._stop.clear()
        self.work_q = Queue()
        self.work_q.put("recv")

    def stop(self):
        print "STOP"
        self._stop.set()

    def request(self, msg):
        self.work_q.put(msg)

    def run(self):
        while True:
            if self._stop.isSet():
                print "stop thread"
                if not self.work_q.empty():
                    print "dump", self.work_q.qsize()
                    # dump queued messages
                    self.work_q.get()
                    self.work_q.task_done()
                    continue
                else:
                    break
            try:
                msg = self.work_q.get_nowait()
                self.do_work(msg)
                self.work_q.task_done()
            except:
                pass
        print "end of thread"

    def do_work(self, msg):
        if msg != "recv":
           print msg
        if msg == "recv":
            self.work_q.put("recv")

if __name__ == "__main__":
    t = test()
    t.start()

    time.sleep(1)
    t.request("haha")
    time.sleep(2)
    t.stop()
    t.join()

