package br.poo.apinewbank.entity;

public class CostumerPremiumEntity extends CostumerEntity{

    private final float MAX_LOAN_AMOUNT = 1000;

    public byte hasEnoughBalance(float money) {
        if(this.getBalance() >= money) {
            return 0;
        } else if(MAX_LOAN_AMOUNT + this.getBalance() >= money) {
            return 1;
        }
        return -1;
    }

}