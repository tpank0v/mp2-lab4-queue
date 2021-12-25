#include "gtest.h"
#include <iostream>
#include "..\Queue\queue.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, cant_create_queue_with_zero_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(0));
}

TEST(TQueue, new_queue_is_not_full)
{
	TQueue<int> q(5);
	ASSERT_FALSE(q.IsFull());
}

TEST(TQueue, full_queue_is_not_empty)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}

	ASSERT_FALSE(q.IsEmpty());
}

TEST(TQueue, full_queue_is_full)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}

	ASSERT_TRUE(q.IsFull());
}

TEST(TQueue, not_empty_queue_is_not_empty)
{
	TQueue<int> q(5);
	q.Push(0);

	ASSERT_FALSE(q.IsEmpty());
}

TEST(TQueue, not_full_queue_is_not_full)
{
	TQueue<int> q(5);
	q.Push(0);

	ASSERT_FALSE(q.IsFull());
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q(5);
	ASSERT_NO_THROW(TQueue<int> copy(q));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}
	TQueue<int> q0 = q;

	EXPECT_EQ(q0, q);
}

TEST(TQueue, copied_queue_has_its_own_memory)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}
	TQueue<int> q0 = q;
	q0.Clear();
	for (int i = 0; i < 5; i++)
	{
		q0.Push(i + 1);
	}
	for (int i = 0; i < 5; i++)
	{
		EXPECT_NE(q0.Pop(), q.Pop());
	}
}

TEST(TQueue, can_assign_queues_of_equal_sizes)
{
	TQueue<int> q1(5);
	for (int i = 0; i < 5; i++)
	{
		q1.Push(i);
	}
	TQueue<int> q2(5);
	q2 = q1;

	EXPECT_EQ(q2, q1);
}

TEST(TQueue, can_assign_queues_of_different_sizes)
{
	TQueue<int> q1(5);
	for (int i = 0; i < 5; i++)
	{
		q1.Push(i);
	}
	TQueue<int> q2(10);
	q2 = q1;

	EXPECT_EQ(q2, q1);
}

TEST(TQueue, new_queue_is_empty)
{
	TQueue<int> q(5);
	ASSERT_TRUE(q.IsEmpty());
}

TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}
	q = q;

	EXPECT_EQ(q, q);
}

TEST(TQueue, queues_with_different_maxsizes_are_not_equal)
{
	TQueue<int> q1(5);
	TQueue<int> q2(10);

	EXPECT_NE(q1, q2);
}

TEST(TQueue, can_push_and_pop_single)
{
	TQueue<double> q(5);
	double num = 22.22;
	double popped;

	ASSERT_NO_THROW(q.Push(num));
	ASSERT_NO_THROW(popped = q.Pop());
	EXPECT_EQ(popped, num);
}

TEST(TQueue, cant_push_to_a_full_queue)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}
	ASSERT_ANY_THROW(q.Push(0));
}

TEST(TQueue, cant_pop_from_an_empty_queue)
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.Pop());
}

TEST(TQueue, can_clear_queue)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}
	ASSERT_NO_THROW(q.Clear());
}

TEST(TQueue, cleared_queue_is_empty)
{
	TQueue<int> q(10);
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}
	q.Clear();
	ASSERT_TRUE(q.IsEmpty());
}

TEST(TQueue, cleared_queue_is_not_full)
{
	TQueue<int> q(10);
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}
	q.Clear();
	ASSERT_FALSE(q.IsFull());
}
