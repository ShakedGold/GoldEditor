use eframe::egui;

use super::Component;

pub struct Item {
    path: String,
    pub is_selected: bool,
}
impl Item {
    pub fn new(path: String) -> Self {
        Self {
            path,
            is_selected: false,
        }
    }
}

impl Component for Item {
    fn render(&self, _ctx: &egui::Context, ui: &mut egui::Ui) -> bool {
        let mut is_clicked = false;
        ui.with_layout(egui::Layout::right_to_left(egui::Align::LEFT), |ui| {
            let width = ui.available_width();
            let display_name = self.path.split("/").last().unwrap();
            let button = ui.add_sized([width, 0.0], egui::Button::new(display_name));
            is_clicked = button.clicked();
        });

        return is_clicked;
    }
}
