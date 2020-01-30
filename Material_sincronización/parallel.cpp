//parallel version of the code count number 3 in a vector with mutex

#include <sys/time.h>
#include "generate_v3.hpp"
#include <thread>
#include <mutex>




double gettime() {
  struct timeval tp;
  gettimeofday(&tp, nullptr);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}


void count3s_thread(const vector<int> &vec, int ini, int fin, int &count, int id, mutex &m) {

  for(int i = ini; i < fin; ++i){
    if(vec[i] == 3){
      m.lock();
      count++;
      m.unlock();

    }
  }
  printf("thread %d has last count at %d\n", id, count);
}

int count3s(const vector<int> &vec){
  int Nthr = thread:: hardware_concurrency(); //No. of threads (Numero de nucleos del computador)
  int size = vec.size();
  int chunk_size = size / Nthr; // cantidad de veces que voy a cortar el vector
  mutex m;

  vector<thread> threads;
  int count = 0;
  for (int thr = 1; thr < Nthr; ++thr) {
    int ini = thr*chunk_size;
    int fin = thr < Nthr-1 ? ini+chunk_size : size;// "?" si es cierto haga lo izquierdo si no lo de la derecha

    threads.emplace_back(thread(count3s_thread, ref(vec), ini, fin, ref(count), thr, ref(m)));
  }
  int ini = 0;
  int fin = chunk_size;
  count3s_thread(vec, ini, fin, count, 0, m);

  for(int thr = 0; thr < Nthr-1; ++thr )
  if (threads[thr].joinable()) {
    threads[thr].join();
  }

  return count;

}


int main(int argc, char** argv) {
  int v_size = atoi(argv[1]);

  vector<int> vec;
  int n3 = generate_vector(v_size, vec);
  cout << "There are " << n3 << " 3s in the vector.\n";

  double tstart = gettime();
  int n = count3s(vec);
  double tstop = gettime();

  cout << "Time: " << tstop-tstart << endl;
  cout << "Number of 3s counted: " << n << endl;

  return 0;
}
