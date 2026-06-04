import numpy as np

class RecentCounter:

    def __init__(self):
        self.calls = np.array([])

    def ping(self, t: int) -> int:
        self.calls = np.append(self.calls, [t])
        self.calls = self.calls[t - self.calls <= 3000]
        return self.calls.shape[0]
