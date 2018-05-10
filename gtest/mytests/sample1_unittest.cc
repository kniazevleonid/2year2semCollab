#include <limits.h>
#include "box.h"
#include "myvector.h"
#include "mylist.h"
#include "gtest/gtest.h"

int CmpInt(void * x, void * y)
{
        int * a = (int *)x;
        int * b = (int *)y;
        if (* a == * b)
                return 1;
        return 0;
}

namespace {

TEST(ListTest, GetNextAndFirst) {
	pbox a = list_create();

        int mass[3];
        mass[0] = 0;
        mass[1] = 1;
        mass[2] = 2;

        data d = &mass[0];

        a->insert(a, d);

        a->insert(a, (int*)d+1);

	a->insert(a, (int*)d+2);

  EXPECT_EQ(1, *((int*)((a->get_next(a, a->first(a)))->data)));
}

TEST(ListTest, Search) {

	pbox a = list_create();

        int mass[3];
        mass[0] = 0;
        mass[1] = 1;
        mass[2] = 2;

        data d = &mass[0];

        a->insert(a, d);

        a->insert(a, (int*)d+1);

	a->insert(a, (int*)d+2);

	int tmp = 1;
        data temp = &tmp; 

  EXPECT_EQ(1, *((int*)((a->search(a, temp, CmpInt))->data)));
}

TEST(ListTest, GetPrevAndLast) {
	pbox a = list_create();

        int mass[3];
        mass[0] = 0;
        mass[1] = 1;
        mass[2] = 2;

        data d = &mass[0];

        a->insert(a, d);

        a->insert(a, (int*)d+1);

	a->insert(a, (int*)d+2);

  EXPECT_EQ(1, *((int*)((a->get_prev(a, a->last(a)))->data)));

	a->delete_element(a, a->first(a));
        a->mydelete(a);
}

TEST(VectorTest, First) {
pbox aa = vector_create();

	int massiv[4];
	massiv[0] = 0;
	massiv[1] = 1;
	massiv[2] = 2;
	massiv[3] = 3;

	data dd = &massiv[0];

	aa->insert(aa, dd);

	aa->insert(aa, (int*)dd+1);

	aa->insert(aa, (int*)dd+2);

	aa->insert(aa, (int*)dd+3);

  EXPECT_EQ(0, *((int*)((aa->first(aa))->data)));
}

TEST(VectorTest, Search) {
pbox aa = vector_create();

	int massiv[4];
	massiv[0] = 0;
	massiv[1] = 1;
	massiv[2] = 2;
	massiv[3] = 3;

	data dd = &massiv[0];

	aa->insert(aa, dd);

	aa->insert(aa, (int*)dd+1);

	aa->insert(aa, (int*)dd+2);

	aa->insert(aa, (int*)dd+3);

	int tmpp = 2;
	data tempp = &tmpp; 
  EXPECT_EQ(2, *((int*)((aa->search(aa, tempp, CmpInt))->data)));
}

TEST(VectorTest, Last) {
pbox aa = vector_create();

	int massiv[4];
	massiv[0] = 0;
	massiv[1] = 1;
	massiv[2] = 2;
	massiv[3] = 3;

	data dd = &massiv[0];

	aa->insert(aa, dd);

	aa->insert(aa, (int*)dd+1);

	aa->insert(aa, (int*)dd+2);

	aa->insert(aa, (int*)dd+3);

  EXPECT_EQ(3, *((int*)((aa->last(aa))->data)));
}

TEST(VectorTest, GetByNum) {
pbox aa = vector_create();

	int massiv[4];
	massiv[0] = 0;
	massiv[1] = 1;
	massiv[2] = 2;
	massiv[3] = 3;

	data dd = &massiv[0];

	aa->insert(aa, dd);

	aa->insert(aa, (int*)dd+1);

	aa->insert(aa, (int*)dd+2);

	aa->insert(aa, (int*)dd+3);

  EXPECT_EQ(1, *((int*)((aa->get_by_num(aa, 1))->data)));
}

TEST(VectorTest, GetNextGetPrevFirst) {
pbox aa = vector_create();

	int massiv[4];
	massiv[0] = 0;
	massiv[1] = 1;
	massiv[2] = 2;
	massiv[3] = 3;

	data dd = &massiv[0];

	aa->insert(aa, dd);

	aa->insert(aa, (int*)dd+1);

	aa->insert(aa, (int*)dd+2);

	aa->insert(aa, (int*)dd+3);

	aa->delete_element(aa, aa->first(aa));

  EXPECT_EQ(1, *((int*)((aa->get_prev(aa, aa->get_next(aa, aa->first(aa))))->data)));

	aa->mydelete(aa);
	aa->mydelete(NULL);
}
}

