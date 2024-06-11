use std::borrow::BorrowMut;

use super::{item, Component};
use eframe::egui;

pub struct Sidebar {
    items: Vec<item::Item>,
}
impl Sidebar {
    pub fn new() -> Self {
        Self { items: vec![] }
    }
    pub fn add_item(&mut self, item: item::Item) {
        self.items.push(item);
    }
}

impl Component for Sidebar {
    fn render(&self, ctx: &egui::Context, _ui: &mut egui::Ui) -> bool {
        egui::SidePanel::left("sidebar").show(ctx, |ui| {
            ui.heading("Gold Editor");
            ui.separator();
            for item in &self.items {
                item.render(ctx, ui);
            }
        });

        false
    }
}
