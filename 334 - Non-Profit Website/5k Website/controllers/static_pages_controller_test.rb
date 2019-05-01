require 'test_helper'

class StaticPagesControllerTest < ActionDispatch::IntegrationTest

  test "should get home" do
    get root_path
    assert_response :success
    assert_select "title", "Ruby on Rails Tutorial Sample App"
  end

  test "should get about" do
    get about_path
    assert_response :success
    assert_select "title", "About | Ruby on Rails Tutorial Sample App"
  end

  test "should get contact" do
    get contact_path
    assert_response :success
    assert_select "title", "Contact | Ruby on Rails Tutorial Sample App"
  end  
  
  test "should get race info" do
    get race_info_path
    assert_response :success
    assert_select "title", "Race Information | Ruby on Rails Tutorial Sample App"
  end
  
  test "should get photo gallery" do
    get photo_gallery_path
    assert_response :success
    assert_select "title", "Photo Gallery | Ruby on Rails Tutorial Sample App"
  end
  
  test "should get detailed race info" do
    get race_detail_info_path
    assert_response :success
    assert_select "title", "Race Detailed Information | Ruby on Rails Tutorial Sample App"
  end
end