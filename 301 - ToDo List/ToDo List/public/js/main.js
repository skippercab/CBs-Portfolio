// Student Name: Christopher Bell
// Program Name: ToDo List
// Creation Date: Mar. 26, 2018
// Last Modified Date: April. 24, 2018
// CSCI Course: 301
// Grade Received: 90/100

$(document).ready(function () {
    $('.deleteTask').on('click', deleteTask)
    $('.updateTask').on('click', getTask)
})

function deleteTask () {
    var confirmation = confirm('Are You Sure?')

    if (confirmation) {
        $.ajax({
            type: 'DELETE',
            url: '/todo/delete/' + $(this).data('id')
        }).done(function (response) {
            window.location.replace('/')
        })
        window.location.replace('/')
    } else {
        return false;
    }
}

function getTask () {
    window.location.replace('/todo/update/' + $(this).data('id'))
}
