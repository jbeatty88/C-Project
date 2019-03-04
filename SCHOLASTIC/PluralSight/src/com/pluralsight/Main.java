package com.pluralsight;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.logging.*;

public class Main {
    public static void main(String[] args) {
        ExecutorService es = Executors.newFixedThreadPool(5);
        BankAccount account = new BankAccount(100);
        for(int i = 0; i < 5; i++) {
            Worker worker = new Worker(account);
            es.submit(worker);
            System.out.println(account.getBalance());
        }
        es.shutdown();
        System.out.println(account.getBalance());
    }
}
