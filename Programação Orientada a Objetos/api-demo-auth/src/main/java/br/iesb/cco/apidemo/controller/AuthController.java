package br.iesb.cco.apidemo.controller;

import br.iesb.cco.apidemo.dto.UserDTO;
import br.iesb.cco.apidemo.service.AuthService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import javax.xml.transform.OutputKeys;

@RestController
public class AuthController {

    @Autowired
    private AuthService service;

    @PostMapping("/login")
    public ResponseEntity<String> login(@RequestBody UserDTO user) {
        String token = service.login(user);

        if (token == null) {
            return ResponseEntity.notFound().build();
        }

        HttpHeaders responseHeader = new HttpHeaders();
        responseHeader.add("Authorization", token);

        return ResponseEntity.ok().headers(responseHeader).build();
    }

    @PostMapping("/signup")
    public ResponseEntity<String> signup(@RequestBody UserDTO user) {

        int result = service.signup(user);

        if (result == 1) {
            return ResponseEntity.badRequest().body("Nome de usuario invalido!");
        } else if (result == 2) {
            return ResponseEntity.badRequest().body("E-mail de usuario invalido!");
        } else if (result == 3) {
            return ResponseEntity.badRequest().body("Senha deve ter mais que 6 caracters.");
        }

        return ResponseEntity.ok().build();
    }

}
