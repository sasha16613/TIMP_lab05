#include <gtest/gtest.h>
#include <Transaction.h>
#include <Account.h>

TEST(Transaction, account) {
    Account Acc(101, 100);
    EXPECT_EQ(Acc.GetBalance(), 100);
}

TEST(Transaction, change_balance) {
    Account Acc(100, 100);
    try {
        Acc.ChangeBalance(100);
    } catch (std::runtime_error& error){
        EXPECT_EQ(error.what(), std::string("at first lock the account"));
    }
    Acc.Lock();
    Acc.ChangeBalance(100);
    EXPECT_EQ(Acc.GetBalance(), 200);
}

TEST(Transaction, transaction_sum) {
    Account fAcc1(100, 110);
    Account fAcc2(101, 101);
    Account tAcc(200, 0);
    Transaction transaction;
    EXPECT_TRUE(transaction.Make(fAcc1, tAcc, 100));
    EXPECT_FALSE(transaction.Make(fAcc2, tAcc, 100));
}

TEST(Transaction, transaction_id) {
    Account Acc(100, 110);
    Transaction transaction;
    try {
        EXPECT_FALSE(transaction.Make(Acc, Acc, 100));
    } catch (std::logic_error& error){
        EXPECT_EQ(error.what(), std::string("invalid action"));
    }
}

