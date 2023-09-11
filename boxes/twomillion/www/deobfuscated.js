function verifyInviteCode(code) {
    var formData = { "code": code };
    $.ajax({
        type: "POST",
        url: '/api/v1/invite',
        dataType: 'json',
        data: formData,
        success: function (data) {
            console.log(data);
        },
        error: function (data) {
            console.error(data);
        }
    });
}

function makeInviteCode() {
    $.ajax({
        type: "POST",
        url: '/api/v1/invite/how/to/generate',
        success: function (data) {
            console.log(data);
        },
        error: function (data) {
            console.error(data);
        }
    });
}
