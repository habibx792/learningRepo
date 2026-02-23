from collections import deque

dq=deque([1,2,3,4])
print(dq)
dq.append(100)
dq.append(1002)
dq.appendleft(100)
dq.appendleft(12)
print(dq)