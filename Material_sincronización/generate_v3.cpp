#include "generate_v3.hpp"

int generate_vector(int size, vector<int> &v) {
  v.clear();
  //rng and distribution
  default_random_engine rng;
  rng.seed(213);
  uniform_int_distribution<int> uniform(0,3); //Uniform dist.

  int count3 = 0;
  for(int i = 0; i < size; ++i){
    int rnum = uniform(rng);
    v.push_back(rnum);
    if(rnum == 3) count3++;
  }
  return count3;
}

void print_vec(const vector<int> &v) {
  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << endl;
}
