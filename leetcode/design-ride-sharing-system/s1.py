from collections import deque
from typing import List


class RideSharingSystem:
    def __init__(self):
        self.rq = deque()
        self.dq = deque()
        self.tq = deque()

    def addRider(self, riderId: int) -> None:
        self.rq.append(riderId)

    def addDriver(self, driverId: int) -> None:
        self.dq.append(driverId)

    def matchDriverWithRider(self) -> List[int]:
        if not self.rq or not self.dq:
            return [-1, -1]
        return [self.dq.popleft(), self.rq.popleft()]

    def cancelRider(self, riderId: int) -> None:
        while self.rq:
            rider = self.rq.pop()
            if rider != riderId:
                self.tq.append(rider)
            else:
                break
        while self.tq:
            self.rq.append(self.tq.pop())


# Your RideSharingSystem object will be instantiated and called as such:
# obj = RideSharingSystem()
# obj.addRider(riderId)
# obj.addDriver(driverId)
# param_3 = obj.matchDriverWithRider()
#
