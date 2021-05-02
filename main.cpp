//6:16
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <functional>
int main(){
    sf::RenderWindow window({800, 500}, "title");


    sf::RectangleShape Timer_Bar({static_cast<float>(sf::VideoMode::getDesktopMode().width), 10});
    Timer_Bar.setFillColor({0x0, 0x0, 0xff});


    Timer_Bar.move(0, 20);
    sf::RectangleShape Health_Bar{{100, 10}};

    sf::Color clear_color{0x0, 0x0, 0x0};

    auto now = std::chrono::steady_clock::now();
    std::function<void()> current_state;
    auto game_state = [hax{500.f}, &window, &Timer_Bar, &now, &Health_Bar ]  () mutable{
        float tp{static_cast<float>( std::chrono::duration_cast<std::chrono::milliseconds>(now - std::chrono::steady_clock::now()).count())};

        hax += (tp * 0.001f);
        std::cout <<tp << ' ' << hax << '\n';

        Timer_Bar.setSize({ static_cast<float>(hax), Timer_Bar.getSize().y });



        window.draw(Timer_Bar);
        window.draw(Health_Bar);
    };
    auto game_over = [&clear_color, toggle{0}]()mutable {
        if(toggle == 0) {toggle++; clear_color = {0xff, 0x0, 0xff};}
        else if(toggle == 1){ toggle++; clear_color = {0xff, 0xff, 0x00}; }
        else toggle = 0;

    };

    current_state = game_state;
    sf::Event event{};
    while(window.isOpen()){
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            std::cout << event.type << '\n';
        }


        window.clear(clear_color);

        current_state();

        if(Timer_Bar.getSize().x <= 0.0f) current_state = game_over;
        window.display();

    }
}