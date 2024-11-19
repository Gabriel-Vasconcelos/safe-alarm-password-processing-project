# Projeto Cofre com Alarme e Senha 🔒
![image](https://github.com/user-attachments/assets/6d776e77-51a8-4e7c-adfc-251512a24a8b)


## Equipe 👨‍💻👩‍💻
- Angelo Lucas
- Gabriel Vasconcelos

## Proposta 💡
Este projeto visa desenvolver um sistema de segurança para um cofre utilizando Arduino e Processing. O cofre é protegido por um sistema de alarme acionado por luminosidade e um mecanismo de desbloqueio baseado em senha. O alarme é disparado quando o cofre detecta a presença de luz, usando um LDR (Light Dependent Resistor), enquanto o desbloqueio é feito por meio de uma senha inserida via potenciômetro. A interface gráfica no Processing serve como a camada visual que permite ao usuário interagir com o sistema de segurança e monitorar o status do alarme e da senha.

## Funcionamento ⚙️:
- O cofre estará equipado com um LDR para detectar variações de luminosidade. Caso o LDR registre uma mudança significativa na intensidade de luz, o alarme será disparado.
- A senha será configurada através de um potenciômetro, permitindo ao usuário inserir um valor específico para desbloquear o cofre. O valor do potenciômetro será lido pelo Arduino e, se corresponder à senha predefinida, o cofre será aberto.
- O sistema de senha será integrado à interface gráfica no Processing, proporcionando uma visualização interativa e mais intuitiva para o usuário.


## Componentes 🧰
- LDR (Light Dependent Resistor) – Para detectar mudanças na luminosidade e acionar o alarme.
- Buzzer – Para emitir som quando o alarme é disparado.
- Resistores – Para garantir o funcionamento correto dos componentes.
- Arduino – A plataforma que controla os sensores e o buzzer.
- Potenciômetro – Usado para inserir a senha no sistema.
- Botão – Para interagir com o sistema (ainda não implementado no código do Processing).
