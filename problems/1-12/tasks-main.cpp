#include <iostream>
#include <math.h>
#include "1-task.cpp"

using namespace std;

void random(tree *t, int length) {
   srand(time(0));
   for (int i = 0; i < length; i++) {
      int num = (rand() % 100)*pow(-1, rand());
      t->add(num);
   }
}

int main() {

  tree *t3 = new tree();
  t3->add(50);
  t3->add(-33);
  t3->add(76);
  t3->add(-64);


//for (int i = -7; i <= 5; i++) {//
//  t3->add(i);
//}
//  tree *t = new tree();
//  random(t3, 10);
  t3->show();
  cout << "////////\n";
  tree *t2 = t3->find_del(3);
  t2->show();
}
