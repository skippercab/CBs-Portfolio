Student Name: Christopher Bell
Program Name: ToDo List
Creation Date: Mar. 26, 2018
Last Modified Date: April. 24, 2018
CSCI Course: 301
Grade Received: 90/100

This app is a todo list that you can access through Heroku and it keeps track of
items on your todo list and whether you have completed them or not.

Make sure you have Node.js and the Heroku CLI installed.

Once you know the above is installed correctly, type the following into the
command terminal:
$ git clone https://github.com/skippercab/csci-301-spring-2018-project
$ cd csci-301-spring-2018-project
$ npm install
$ npm start

Your app should now be running on localhost:5000.

Next, to deploy to Heroku, type the following into command terminal:
$ heroku create
$ git push heroku master
$ heroku open
