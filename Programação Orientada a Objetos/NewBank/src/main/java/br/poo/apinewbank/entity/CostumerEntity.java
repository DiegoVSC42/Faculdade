package br.poo.apinewbank.entity;


public class CostumerEntity {

    private long id;
    private String name;
    private String accountNumber;
    private float balance = 0;
    private String creationDate;
    private String CPF;

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
        this.balance += money;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public void setAccountNumber(String accountNumber) {
        this.accountNumber = accountNumber;
    }

    public float getBalance() {
        return balance;
    }

    public void setBalance(float balance) {
        this.balance = balance;
    }

    public String getCreationDate() {
        return creationDate;
    }

    public void setCreationDate(String creationDate) {
        this.creationDate = creationDate;
    }

    public String getCPF() {
        return CPF;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }
}



