template<typename T>
void calculate(T &max, T &min, T array[], int number) {
  if(number != 0) {
    max = array[0];
    min = array[0];
    for (int i = 1; i < number; ++i) {
      max = array[i] > max ? array[i] : max;
      min = array[i] < min ? array[i] : min;
    }
  }
}
