package br.poo.apinewbank.service;

import br.poo.apinewbank.repository.CostumerRepository;

import java.util.Random;

public class CostumerService {

    // Numero de digitos da conta pode ter até 8 digitos
    private int MAX_ACCOUNT_NUMBER = (int)Math.pow(10, 8);

    Random rand = new Random();
    CostumerRepository repository = new CostumerRepository();

    private String convertIntToAccountNumber(int accountNumber) {
        int account = accountNumber/10; // Primeiros digitos
        int digit = accountNumber - account*10; // Ultimo digito
        return String.format("%07d-%d", account, digit);
    }

    public String generateAccountNumber() {
        int accountNumber = rand.nextInt(MAX_ACCOUNT_NUMBER);

        while (repository.accountAlreadyExists(accountNumber)) {
            accountNumber = rand.nextInt(MAX_ACCOUNT_NUMBER);
        }
        repository.includeNewAccountNumber(accountNumber); // Registra novo numero de conta

        return convertIntToAccountNumber(accountNumber);
    }

}
