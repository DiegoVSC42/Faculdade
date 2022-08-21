package br.iesb.cco.apidemo.controller;

import br.iesb.cco.apidemo.dto.SimpletronDTO;
import br.iesb.cco.apidemo.service.SimpletronService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class SimpletronController {

    @Autowired
    private SimpletronService service;

    @GetMapping("/computers")
    public List<SimpletronDTO> getComputers() {
        List<SimpletronDTO> dtos = service.getComputers();
        return dtos;
    }

}
