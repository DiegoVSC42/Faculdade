package br.poo.apinewbank.service;

import br.poo.apinewbank.dto.CostumerDTO;
import br.poo.apinewbank.entity.CostumerEntity;
import br.poo.apinewbank.entity.UserEntity;
import br.poo.apinewbank.repository.CostumerRepository;
import org.springframework.beans.factory.annotation.Autowired;

import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
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

    public String getCurrentDate() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        return java.time.LocalDateTime.now().format(formatter);
    }

    CostumerRepository repo = new CostumerRepository();

    public List<CostumerDTO> getCostumers() {
        List<CostumerDTO> listComputers = new ArrayList<>();

        List<UserEntity> comps = repo.get();
        for (int i = 0; i < comps.size(); i++) {
            UserEntity tmp = comps.get(i);

            CostumerDTO dto = new CostumerDTO();
            dto.setName(tmp.getName());
            dto.setAccountNumber(tmp.getAccountNumber());
            dto.setCPF(tmp.getCPF());
            listComputers.add(dto);
        }

        return listComputers;
    }

}
