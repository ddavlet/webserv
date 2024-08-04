from base_test_script import *

def test_400_bad_request_invalid_host():
    # Test for invalid host in headers
    response = requests.get(f"{BASE_URL}", headers={"Host": "invalid host"})
    return check_status_code(response, 400, "Invalid host in headers")

def test_400_bad_request_incorrect_content_type():
    # Test for incorrect content type
    response = requests.post(f"{BASE_URL}/api/resource", data="plain text", headers={"Content-Type": "application/json"})
    return check_status_code(response, 400, "Incorrect content type")


if __name__ == "__main__":
    run_test(test_400_bad_request_invalid_host)
    run_test(test_400_bad_request_incorrect_content_type)