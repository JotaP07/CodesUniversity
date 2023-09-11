class Column {
    constructor(id) {
        this.id = id;
        this.isEditing = false;

        this.element = this.createColumnElement();
        this.titleElement = this.createTitleElement();
        this.addTaskButton = this.createAddTaskButton();
        this.cancelButton = this.createCancelButton();

        this.element.appendChild(this.titleElement);
        this.element.appendChild(this.addTaskButton);
        this.element.appendChild(this.cancelButton);

        this.addEvents();
    }

    createColumnElement() {
        const columnElement = document.createElement('div');
        columnElement.className = 'listTasks';
        columnElement.id = `listTasks-${this.id}`;
        return columnElement;
    }

    createTitleElement() {
        const titleElement = document.createElement('div');
        titleElement.className = 'columnTitle';
        titleElement.textContent = 'Clique duas vezes para editar';
        titleElement.addEventListener('dblclick', this.toggleEdit.bind(this));
        return titleElement;
    }

    createAddTaskButton() {
        const addTaskButton = document.createElement('button');
        addTaskButton.innerText = 'Adicionar Tarefa';
        addTaskButton.style.display = 'none';
        addTaskButton.addEventListener('click', this.addTask.bind(this));
        return addTaskButton;
    }

    createCancelButton() {
        const cancelButton = document.createElement('button');
        cancelButton.innerText = 'X';
        cancelButton.addEventListener('click', () => {
            this.element.remove();
        });
        return cancelButton;
    }

    toggleEdit() {
        if (!this.isEditing) {
            this.isEditing = true;
            const titleInput = document.createElement('input');
            titleInput.type = 'text';
            titleInput.value = this.titleElement.textContent;

            titleInput.addEventListener('blur', () => {
                this.titleElement.textContent = titleInput.value;
                titleInput.remove();
                this.isEditing = false;
            });

            this.titleElement.textContent = '';
            this.titleElement.appendChild(titleInput);
            titleInput.focus();
        }
    }

    addTask() {
        // Implemente a lógica para adicionar tarefas aqui
    }

    addEvents() {
        // Adicione outros eventos necessários aqui
    }
}

const addColumnBtn = document.getElementById('addColumnBtn');
const mainContent = document.getElementById('mainContent');
let idControl = 0;

function createColumn() {
    const column = new Column(idControl);
    mainContent.appendChild(column.element);
    idControl++;
}

addColumnBtn.addEventListener('click', createColumn);
