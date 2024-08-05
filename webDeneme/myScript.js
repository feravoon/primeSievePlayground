var userName = document.querySelector('#userName');
var userNameInput = userName.querySelector('input');
userNameInput.addEventListener("focus", userNameFocus);
userNameInput.addEventListener("focusout", userNameFocusOut);

var password = document.querySelector('#password');
var passwordInput = password.querySelector('input');
passwordInput.addEventListener("focus", passwordFocus);
passwordInput.addEventListener("focusout", passwordFocusOut);

function userNameFocus() {
    if(userNameInput.style.color.length === 0)
    {
        userNameInput.style.color = '#777777';
    }
    if(userNameInput.value === 'Username'){
        userNameInput.style.color = '#000000';
        userNameInput.value = '';
    }
}

function userNameFocusOut() {
    
    if(userNameInput.value.length === 0)
    {
        userNameInput.style.color = '#777777';
        userNameInput.value = 'Username';
    }
}

function passwordFocus() {
    if(passwordInput.style.color.length === 0)
    {
        passwordInput.style.color = '#777777';
    }
    if(passwordInput.value === 'Password'){
        passwordInput.style.color = '#000000';
        passwordInput.value = '';
        passwordInput.type = 'password';
    }
}

function passwordFocusOut() {
    
    if(passwordInput.value.length === 0)
    {
        passwordInput.style.color = '#777777';
        passwordInput.value = 'Password';
        passwordInput.type = 'text';
    }
}