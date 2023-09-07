// Função para adicionar uma nova coluna
function addColumn(title) {
    const board = document.querySelector('.board');
    const column = document.createElement('div');
    column.className = 'column';
    column.innerHTML = `
        <div class="column-header">
            <h3>${title}</h3>
            <button class="delete-column-btn">X</button>
        </div>
        <div class="column-content">
            <ul class="card-list"></ul>
            <form class="add-card-form">
                <input type="text" class="card-title" placeholder="Título do Cartão">
                <button type="submit">Adicionar Cartão</button>
            </form>
        </div>
    `;

    // Event listener para excluir colunas
    const deleteColumnBtn = column.querySelector('.delete-column-btn');
    deleteColumnBtn.addEventListener('click', function () {
        board.removeChild(column);
    });

    // Event listener para adicionar cartões
    const addCardForm = column.querySelector('.add-card-form');
    const cardList = column.querySelector('.card-list');

    addCardForm.addEventListener('submit', function (e) {
        e.preventDefault();
        const cardTitle = addCardForm.querySelector('.card-title').value;
        if (cardTitle.trim() !== '') {
            const card = document.createElement('li');
            card.className = 'card';
            card.innerHTML = `
                <p>${cardTitle}</p>
                <button class="delete-card-btn">X</button>
            `;
            
            // Event listener para excluir cartões
            const deleteCardBtn = card.querySelector('.delete-card-btn');
            deleteCardBtn.addEventListener('click', function () {
                cardList.removeChild(card);
            });

            cardList.appendChild(card);
            addCardForm.reset();
        }
    });

    board.appendChild(column);
}

// Event listener para adicionar colunas
const addListForm = document.querySelector('.add-list-form');
addListForm.addEventListener('submit', function (e) {
    e.preventDefault();
    const listTitle = addListForm.querySelector('.list-title').value;
    if (listTitle.trim() !== '') {
        addColumn(listTitle); // Passar o título da coluna para a função
        addListForm.reset();
    }
});
