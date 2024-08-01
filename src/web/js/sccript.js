document.addEventListener('DOMContentLoaded', function() {
    fetch('/data/data.json')
        .then(response => response.json())
        .then(data => {
            const contentDiv = document.getElementById('json-content');
            contentDiv.innerHTML = `
                <h2>${data.message}</h2>
                <p>Author: ${data.author}</p>
                <p>Year: ${data.year}</p>
                <h3>Features:</h3>
                <ul>
                    ${data.features.map(feature => `<li>${feature}</li>`).join('')}
                </ul>
                <h3>Contact:</h3>
                <p>Email: ${data.contact.email}</p>
                <p>Twitter: ${data.contact.twitter}</p>
            `;
        })
        .catch(error => console.error('Error loading JSON:', error));
});
