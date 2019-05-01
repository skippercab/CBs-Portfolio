class AddTeamnameToUsers < ActiveRecord::Migration[5.2]
  def change
    add_column :users, :team_name, :string
    add_column :users, :first_name, :string
    add_column :users, :last_name, :string
    add_column :users, :phoneNumber, :string
    add_column :users, :age, :integer
    
  end
end
