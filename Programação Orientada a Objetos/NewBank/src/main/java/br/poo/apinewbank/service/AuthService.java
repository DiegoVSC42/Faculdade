package br.poo.apinewbank.service;

import br.poo.apinewbank.entity.UserEntity;
import org.springframework.stereotype.Service;

import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

@Service
public class AuthService {

    private List<UserEntity> users = new ArrayList<>();

    public String login(UserEntity user){

        String accountNumber = user.getAccountNumber();
        String password = user.getPassword();

        for(UserEntity u : users){
            if(u.getAccountNumber().equals(accountNumber) && u.getPassword().equals(password)){
                return u.getToken();
            }
        }
        return null;
    }
    public String getCurrentDate() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        return java.time.LocalDateTime.now().format(formatter);
    }

    public int signup(UserEntity user) {

        if (user.getName().trim().equals("") || user.getName().trim().split(" ").length < 2) {
            return 1;
        }

        if (user.getPassword().length() < 6) {
            return 2;
        }
        CostumerService generator = new CostumerService();

        UserEntity entity = new UserEntity();

        entity.setName(user.getName());
        entity.setAccountNumber(generator.generateAccountNumber());
        entity.setPassword(user.getPassword());
        generator.generateAccountNumber();
        String token = UUID.randomUUID().toString();
        entity.setToken(token);
        users.add(entity); //NA VERSAO FINAL DO PROJETO DEVE GRAVAR NO BANCO DE DADOS
        // DENTRO DA REPOSITORY

        return 0;
    }

}
