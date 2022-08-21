package br.iesb.cco.apidemo.service;

import br.iesb.cco.apidemo.dto.SimpletronDTO;
import br.iesb.cco.apidemo.model.SimpletronEntity;
import br.iesb.cco.apidemo.repository.SimpletronRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class SimpletronService {

    @Autowired
    private SimpletronRepository repo;

    public List<SimpletronDTO> getComputers() {
        List<SimpletronDTO> listComputers = new ArrayList<>();
        
        List<SimpletronEntity> comps = repo.get();
        for (int i = 0; i < comps.size(); i++) {
            SimpletronEntity tmp = comps.get(i);

            SimpletronDTO dto = new SimpletronDTO();
            dto.setName(tmp.getName());
            dto.setBrand(tmp.getBrand());
            dto.setDescription(tmp.getDescription());
            dto.setInstructions(tmp.getInstructions());

            listComputers.add(dto);
        }

        return listComputers;
    }

}
