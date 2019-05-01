Rails.application.routes.draw do
  get 'sessions/new'
  root 'static_pages#home'
  get  '/about',   to: 'static_pages#about'
  get  '/contact', to: 'static_pages#contact'
  get  '/race_info', to: 'static_pages#race_info'
  get  '/race_detail_info', to: 'static_pages#race_detail_info'
  get  '/photo_gallery', to: 'static_pages#photo_gallery'
  get  '/signup',  to: 'users#new'
  post '/signup',  to: 'users#create'
  get    '/login',   to: 'sessions#new'
  post   '/login',   to: 'sessions#create'
  delete '/logout',  to: 'sessions#destroy'
  resources :users
end