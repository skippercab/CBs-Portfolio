# Charleston Women in Tech 5K Race Application

This is the web application for the 5K Race to support by Charleston Women in
Tech. 

## License

All source code is available under the MIT License.

## Getting started

To get started with the app, clone the repo and then install the needed gems:

```
$ bundle install --without production
```

Next, migrate the database:

```
$ rails db:migrate
```

Finally, run the test suite to verify that everything is working correctly:

```
$ rails test
```

If the test suite passes, you'll be ready to run the app in a local server:

```
$ rails server
```

## Run app in production environment (Heroku)

You can run the web application at:
[https://bravo-project-334sp19.herokuapp.com/](https://bravo-project-334sp19.herokuapp.com/)