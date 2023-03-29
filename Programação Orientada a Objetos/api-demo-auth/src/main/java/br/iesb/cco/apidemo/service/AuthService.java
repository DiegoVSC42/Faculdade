package br.iesb.cco.apidemo.service;

import br.iesb.cco.apidemo.dto.UserDTO;
import br.iesb.cco.apidemo.model.UserEntity;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

@Service
@Scope("singleton")
public class AuthService {

    private List<UserEntity> users = new ArrayList<>();

    public String login(UserDTO user) {
        String email = user.getEmail();
        String pass = user.getPassword();

        for (UserEntity u : users) {
            if (u.getEmail().equals(email) && u.getPassword().equals(pass)) {
                return u.getToken();
            }
        }
        return null;
    }

    public int signup(UserDTO user) {
        if (user.getName().trim().equals("") || user.getName().trim().split(" ").length < 2) {
            return 1;
        }

        if (!user.getEmail().contains("@")) {
            return 2;
        }

        if (user.getPassword().length() < 6) {
            return 3;
        }

        UserEntity entity = new UserEntity();
        entity.setName(user.getName());
        entity.setEmail(user.getEmail());
        entity.setPassword(user.getPassword());

        String token = UUID.randomUUID().toString();
        entity.setToken(token);

        users.add(entity); //NA VERSAO FINAL DO PROJETO DEVE GRAVAR NO BANCO DE DADOS
                            // DENTRO DA REPOSITORY

        return 0;
    }

}
