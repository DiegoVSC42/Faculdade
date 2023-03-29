package br.poo.apinewbank.dto;

public class UserDTO {

    private String name;
    private String accountNumber;
    private String CPF;

    public String getCPF() {
        return CPF;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAccount_number() {
        return accountNumber;
    }

    public void setAccount_number(String account_number) {
        this.accountNumber = account_number;
    }

}
