"""
Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out
the median of the list so far on each new element.
"""

import heapq


class runningMedian:
    def __init__(self):
        self.min_heap = list()
        self.max_heap = list()

    def balance(self) -> None:
        max_heap_len, min_heap_len = len(self.max_heap), len(self.min_heap)
        if abs(max_heap_len - min_heap_len) > 1:
            if max_heap_len > min_heap_len:
                temp = heapq.nlargest(1, self.max_heap)[0]
                heapq.heappush(self.min_heap, temp)
                self.max_heap.remove(temp)
            else:
                temp = heapq.nsmallest(1, self.min_heap)[0]
                heapq.heappush(self.max_heap, temp)
                self.min_heap.remove(temp)
        return None

    def find_median(self) -> float:
        max_heap_len, min_heap_len = len(self.max_heap), len(self.min_heap)
        if max_heap_len == min_heap_len:
            return (heapq.nsmallest(1, self.min_heap)[0] + heapq.nlargest(1, self.max_heap)[0]) / 2
        else:
            if max_heap_len > min_heap_len:
                return heapq.nlargest(1, self.max_heap)[0]
            else:
                return heapq.nsmallest(1, self.min_heap)[0]

    def insert(self, num: int) -> None:
        if len(self.max_heap) == 0 and len(self.max_heap) == 0:
            self.max_heap.append(num)
            heapq._heapify_max(self.max_heap)  # using a private function to make max-heap 
        elif num <= self.max_heap[-1]:
            heapq.heappush(self.max_heap, num)
        else:
            self.min_heap.append(num)
            heapq.heapify(self.min_heap)
        self.balance()
        if len(self.min_heap) == 0 and len(self.max_heap) == 1:
            print(f'After Adding {num}, the Meddian Is: {heapq.nlargest(1, self.max_heap)[0]}')
        else:
            print(f'After Adding {num}, the Meddian Is: {self.find_median()}')


def main():
    obj1 = runningMedian()
    nums = [2, 1, 5, 7, 2, 0, 5]
    for num in nums:
        obj1.insert(num)


if __name__ == "__main__":
    main()
