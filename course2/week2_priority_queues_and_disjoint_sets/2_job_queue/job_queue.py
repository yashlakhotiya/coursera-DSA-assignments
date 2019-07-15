
#python3
import heapq

class Worker:
    def __init__(self,id,end_time=0):
        self.id = id
        self.end_time = end_time

    def __lt__(self,other):
        if self.end_time == other.end_time:
            return self.id < other.id
        return self.end_time < other.end_time

    def __gt__(self,other):
        if self.end_time == other.end_time:
            return self.id > other.id
        return self.end_time > other.end_time

class JobQueue:
    def read_data(self):
        self.num_workers, m = map(int, input().split())
        self.jobs = list(map(int, input().split()))
        assert m == len(self.jobs)

    def write_response(self):
        for tid,end_time in self.result:
            print(tid,end_time)

    def assign_jobs(self):
        # TODO: replace this code with a faster algorithm.
        self.result = list()
        self.worker_queue = [Worker(i) for i in range(self.num_workers)]
        for job in self.jobs:
            worker = heapq.heappop(self.worker_queue)
            self.result.append((worker.id,worker.end_time))
            worker.end_time = worker.end_time + job
            heapq.heappush(self.worker_queue,worker)
        '''self.assigned_workers = [None] * len(self.jobs)
        self.start_times = [None] * len(self.jobs)
        next_free_time = [0] * self.num_workers
        for i in range(len(self.jobs)):
          next_worker = 0
          for j in range(self.num_workers):
            if next_free_time[j] < next_free_time[next_worker]:
              next_worker = j
          self.assigned_workers[i] = next_worker
          self.start_times[i] = next_free_time[next_worker]
          next_free_time[next_worker] += self.jobs[i]'''

    def solve(self):
        self.read_data()
        self.assign_jobs()
        self.write_response()

if __name__ == '__main__':
    job_queue = JobQueue()
    job_queue.solve()

