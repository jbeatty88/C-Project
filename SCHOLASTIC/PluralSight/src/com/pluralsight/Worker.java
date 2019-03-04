package com.pluralsight;

public class Worker implements Runnable {
    private BankAccount account;
    public Worker(BankAccount account) {
        this.account = account;
    }
    @Override
    public void run() {
        for(int i = 0; i < 10; i++) {
            synchronized (account) {
                account.deposit(10);
            }

        }
    }
}

