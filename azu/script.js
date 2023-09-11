const addColumnBtn = document.getElementById('addColumnBtn');
const mainContent = document.getElementById('mainContent');
let idControl = 0;

function createColumn() {
    const newColumn = document.createElement('div');
    newColumn.className = 'listTasks';
    newColumn.id = 'listTasks-' + idControl;

    const newDiv = document.createElement('div');
    newDiv.className = 'addTaskContent';

    const newInput = document.createElement('input');
    newInput.type = 'text';
    
    newInput.placeholder = 'Adicione uma Task';
    const newButton = document.createElement('button');
    newButton.innerText = '+';
    newButton.id = 'addTaskBtn';
    newButton.addEventListener('click', () => {
        addTask(newInput, newColumn);
    });

    const removeColumnBtn = document.createElement('button');
    removeColumnBtn.innerText = 'Remover Coluna';
    removeColumnBtn.className = 'removeColumnBtn';
    removeColumnBtn.addEventListener('click', () => {
        newColumn.remove();
    });

    newDiv.append(newInput, newButton);
    newColumn.append(newDiv, removeColumnBtn);
    mainContent.appendChild(newColumn);

    // adicionar a ordenação - drag and drop -
    new Sortable(newColumn, {
        animation: 350,
        handle: '.taskContent' // seleciona o elemento que irá aparecer no drag
    });

    idControl++;
}

function addTask(inputElement, columnElement) {
    const taskText = inputElement.value.trim();

    if (taskText !== '') {
        const newDiv = document.createElement('div');
        newDiv.className = 'taskContent';

        const newTask = document.createElement('div'); 
        newTask.innerText = taskText;
        newTask.className = 'task';

        const removeBtn = document.createElement('button');   // Adicione o botão de remoção à tarefa
        removeBtn.className = 'removeBtn';
        removeBtn.innerText = 'x';
        removeBtn.addEventListener('click', () => {
            // Remove a tarefa quando o botão "X" é clicado
            newDiv.remove();
        });

        newDiv.appendChild(newTask);// Adicione a tarefa na coluna
        newDiv.appendChild(removeBtn); // Adicione o botão de remoção à tarefa

        columnElement.appendChild(newDiv);

        inputElement.value = '';
    } else {
        alert("Por favor, adicione uma tarefa!");
    }
}

addColumnBtn.addEventListener('click', createColumn);
