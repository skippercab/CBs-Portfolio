// Student Name: Christopher Bell
// Program Name: ToDo List
// Creation Date: Mar. 26, 2018
// Last Modified Date: April. 24, 2018
// CSCI Course: 301
// Grade Received: 90/100

var express = require('express')
var bodyParser = require('body-parser')
var path = require('path');
var expressValidator = require('express-validator')
var mongojs = require('mongojs')
var db = mongojs('todo', ['process.env.MONGODB_URI'])
var ObjectId = mongojs.ObjectId

var app = express()

app.set('port', (process.env.PORT || 5000))

// View Engine
app.set('view engine', 'ejs')
app.set('views', path.join(__dirname, 'views'))

// Body Parser middleware
app.use(bodyParser.json())
app.use(bodyParser.urlencoded({extended: false}))

// Set static path
app.use(express.static(path.join(__dirname, 'public')))

// Global Vars
app.use(function(req, res, next) {
    res.locals.errors = null
    next()
})

// Express Validator Middleware
app.use(expressValidator({
  errorFormatter: function(param, msg, value) {
      var namespace = param.split('.')
      , root    = namespace.shift()
      , formParam = root;

    while(namespace.length) {
      formParam += '[' + namespace.shift() + ']';
    }
    return {
      param : formParam,
      msg   : msg,
      value : value
    };
  }
}))

// SetUp Routes
app.get('/', function (req, res) {
    db.students.find(function (err, docs) {
	    res.render('index', {
        title: 'TO DO:',
        todo: docs
        })
    })
})

app.post('/todo/add', function (req, res) {

    req.checkBody('Task', 'Task is Required').notEmpty()
    req.checkBody('Description', 'Description is Required').notEmpty()
    req.checkBody('Status', 'Status is Required').notEmpty()

	var validation = req.getValidationResult()

	var task = {
        taskTitle: req.body.taskTitle,
    	description: req.body.description,
    	status: req.body.status
    }

    // insert the new student into the database
    db.todo.insert(task, function (err, result) {
        if (err) {
            console.log(err)
        }
        res.redirect('/')
    })
})

app.delete('/todo/delete/:id', function(req, res) {
    db.todo.remove( { _id: ObjectId(req.params.id) }, function (err, result) {
        if (err) {
            console.log(err)
        }
        res.redirect('/')
    })
})

app.get('/todo/update/:id', function (req, res) {
    db.todo.find( { _id: ObjectId(req.params.id) }, function (err, docs) {
	    res.render('update-task', {
        task: docs[0]
        })
    })
})

app.put('/todo/update', function (req, res) {
    var task = {
        "_id": ObjectId(req.body.id),
        "taskTitle": req.body.taskTitle,
        "description": req.body.description,
        "status": req.body.status
    }
    db.todo.save(task, function (err, result) {
        if (err) {
            console.log(err)
        }
        res.redirect('/')
    })
})

app.listen(app.get('port'), function () {
    console.log('Server started on port ' + app.get('port') + '. . .')
})
