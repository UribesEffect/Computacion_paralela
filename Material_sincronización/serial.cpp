//Serial version of the code count number 3 in a vector

#include <sys/time.h>
#include "generate_v3.hpp"




double gettime() {
  struct timeval tp;
  gettimeofday(&tp, nullptr);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}


int count3s(const vector<int> &vec) {
  int count = 0;
  for(int i = 0; i < vec.size(); ++i){
    if(vec[i] == 3)
      count++;
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
