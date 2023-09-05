// Seleciona o botão e o formulário
const inscreverBtn = document.getElementById('inscreverBtn');
const formulario = document.getElementById('formulario');

// Exibe o formulário quando o botão é clicado
inscreverBtn.addEventListener('click', () => {
  formulario.style.display = 'block';
  inscreverBtn.style.display = 'none';
});

// Lida com o envio do formulário
formulario.addEventListener('submit', (e) => {
  e.preventDefault();
  
  // Coleta os dados do formulário
  const nome = document.getElementById('nome').value;
  const email = document.getElementById('email').value;
  
  // Salva os dados do usuário em algum lugar (por exemplo, em um banco de dados)
  // Envie um e-mail de confirmação ou adicione o usuário à lista de espera para a beta
});
