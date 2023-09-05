const express = require('express');
const mongoose = require('mongoose');
const app = express();
const port = 3000;

// Conecte-se ao MongoDB (substitua a URL pelo seu próprio banco de dados)
mongoose.connect('mongodb://localhost/usuarios', {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

// Defina o modelo User
const User = mongoose.model('User', {
  nome: String,
  email: String,
});

// Configurar rota para servir o seu arquivo HTML
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/Beta-test.html');
});

// Middleware para processar dados do formulário
app.use(express.urlencoded({ extended: true }));

// Rota para lidar com a inscrição
app.post('/inscrever', async (req, res) => {
  try {
    const { nome, email } = req.body;

    // Valide os dados do usuário aqui, se necessário
    if (!nome || !email) {
      return res.status(400).json({ error: 'Nome e e-mail são obrigatórios.' });
    }

    // Crie um novo usuário e salve-o no banco de dados (MongoDB)
    const newUser = new User({ nome, email });
    await newUser.save();

    // Envie um e-mail de confirmação, se necessário
    // (Você precisará configurar um serviço de e-mail para isso)

    // Envie uma resposta de sucesso para o cliente
    res.status(200).json({ message: 'Inscrição realizada com sucesso!' });
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: 'Erro ao processar inscrição.' });
  }
});

app.listen(port, () => {
  console.log(`Servidor está rodando na porta ${port}`);
});
