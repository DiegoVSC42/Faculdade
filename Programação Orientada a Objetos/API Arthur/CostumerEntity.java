package br.poo.apinewbank.entity;

public class CostumerEntity {

    private float balance = 0;

    public byte hasEnoughBalance(float money) {
        if(this.balance >= money) {
            return 0;
        }
        return -1;
    }

    public void withdraw(float money) {
        this.balance -= money;
    }

    public void deposit(float money) {
        this.balance += money;
    }

    public void transfer(float money) {
        this.balance -= money;
    }

    public void receive(float money) {
        this.setBalance(this.getBalance() + money);
    }

    public float getBalance() {
        return balance;
    }

    public void setBalance(float balance) {
        this.balance = balance;
    }
}
