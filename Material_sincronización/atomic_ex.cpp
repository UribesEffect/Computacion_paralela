#include <thread>
#include <atomic>
#include <vector>
#include <cstdio>
using namespace std;

int vec_add_atomic(vector<int>& vec, int ini, int fin,
		   atomic<int>& sum, int id) {
  for(int i = ini; i < fin; ++i)
    sum += vec[i]; //atomic add
  return sum;
}

int main() {
  vector<int> vec(1000, 1);

  atomic<int> sum(0);

  int Nthr = thread::hardware_concurrency(); //No. of threads
  int size = vec.size();
  int chunk_size = size / Nthr; //size of vector sections
  vector<thread> threads;
  for(int thr = 1; thr < Nthr; ++thr){
    int ini = thr*chunk_size;
    int fin = thr < Nthr-1 ? ini+chunk_size : size;

    threads.emplace_back(vec_add_atomic, ref(vec), ini, fin,
			 ref(sum), thr);
  }
  int ini = 0;
  int fin = chunk_size;
  vec_add_atomic(vec, ini, fin, sum, 0);

  for(int thr = 0; thr < Nthr-1; ++thr){
    if(threads[thr].joinable())
      threads[thr].join();
  }

  int res = sum;
  printf("sum = %d\n",res);

  return 0;
}
