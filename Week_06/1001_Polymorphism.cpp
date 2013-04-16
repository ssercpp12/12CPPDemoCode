// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

//////////////////// The code which should submit //////////////////////
#include <algorithm>

int cmp(const TaoBaoItem& i1, const TaoBaoItem& i2) {
  return i1.price > i2.price;
}

int cmp2(const TaoBaoItem& i1, const TaoBaoItem& i2) {
  return i1.volume_of_sales > i2.volume_of_sales;
}

class SortByPrice : public SortInterface {
 public:
  virtual void DoSort(TaoBaoItem item[], int size) {
    sort(item, item + size, cmp);
  }
};

class SortBySales : public SortInterface {
 public:
  virtual void DoSort(TaoBaoItem item[], int size) {
    sort(item, item + size, cmp2);
  }
};

class TaoBao {
 public:
  explicit TaoBao(SortInterface* strategy) : strategy_(strategy) {}

  void SetSortStrategy(SortInterface* strategy) { strategy_ = strategy; }

  void sort(TaoBaoItem item[], int size) {
    strategy_->DoSort(item, size);
  }

 private:
  SortInterface *strategy_;
};
