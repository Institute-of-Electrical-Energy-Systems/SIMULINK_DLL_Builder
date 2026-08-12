from pygments.style import Style
from pygments.token import Comment, Keyword, Name, Number, Operator, String, Text


class NetomacStyle(Style):
    """Pygments style approximating the PSS(R)NETOMAC editor's colors."""

    background_color = "#ffffff"
    default_style = ""

    styles = {
        Text:            "#000000",
        Comment:         "#7ea74d",   # $ ... and ! ... lines
        Keyword:         "bold #a31515",     # [[Section]] headers
        Operator:        "bold #a31515",     # @ and @@
        Name.Variable:   "#267f99",          # #Vn, #Rc, #\MAC\...
        String:          "#267f99",          # 'VSrc', 'IBR'
        Number:          "#000000",
    }
