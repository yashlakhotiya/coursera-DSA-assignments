# python3

class Query:

    def __init__(self, query):
        self.type = query[0]
        if self.type == 'check':
            self.ind = int(query[1])
        else:
            self.s = query[1]


class QueryProcessor:
    _multiplier = 263
    _prime = 1000000007

    def init_list_objects(self):
        a = list()
        for _ in range(self.bucket_count):
            a.append(list())
        return a

    def __init__(self, bucket_count):
        self.bucket_count = bucket_count
        # store all strings in one list
        self.elems = self.init_list_objects()

    def _hash_func(self, s):
        ans = 0
        for c in reversed(s):
            ans = (ans * self._multiplier + ord(c)) % self._prime
        return ans % self.bucket_count

    '''def write_search_result(self, was_found):
        print('yes' if was_found else 'no')'''

    def write_chain(self, chain):
        print(' '.join(chain))

    def read_query(self):
        return Query(input().split())

    def process_query(self, query):
        if query.type == "check":
            # use reverse order, because we append strings to the end
            '''self.write_chain(cur for cur in reversed(self.elems)
                        if self._hash_func(cur) == query.ind)'''
            lst = self.elems[query.ind]
            self.write_chain(lst)
        else:
            ind = self._hash_func(query.s)
            if query.type == 'find':
                lst = self.elems[ind]
                print('yes' if query.s in lst else 'no')
            elif query.type == 'add':
                lst = self.elems[self._hash_func(query.s)]
                if query.s not in lst:
                    lst.insert(0,query.s)
                self.elems[self._hash_func(query.s)] = lst
            else:
                lst = self.elems[self._hash_func(query.s)]
                if query.s in lst:
                    lst.remove(query.s)

    def process_queries(self):
        n = int(input())
        for i in range(n):
            self.process_query(self.read_query())

if __name__ == '__main__':
    bucket_count = int(input())
    proc = QueryProcessor(bucket_count)
    proc.process_queries()