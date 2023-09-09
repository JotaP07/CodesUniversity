const cards = document.querySelectorAll('.card');

cards.forEach((card) => {
  card.addEventListener('dragstart', (e) => {
    e.dataTransfer.setData('text/plain', e.target.id);
    e.target.classList.add('dragging');
  });

  card.addEventListener('dragend', (e) => {
    e.target.classList.remove('dragging');
  });
});

document.querySelectorAll('.column').forEach((column) => {
  column.addEventListener('dragover', (e) => {
    e.preventDefault();
  });

  column.addEventListener('dragenter', (e) => {
    e.preventDefault();
  });

  column.addEventListener('drop', (e) => {
    e.preventDefault();
    const cardId = e.dataTransfer.getData('text/plain');
    const card = document.getElementById(cardId);

    if (card) {
      column.appendChild(card);
    }
  });
});
